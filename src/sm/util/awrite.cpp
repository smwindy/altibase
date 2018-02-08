/***********************************************************************
 * Copyright 1999-2008, ALTIBase Corporation or its subsidiaries.
 * All rights reserved.
 **********************************************************************/

/***********************************************************************
 * $Id:
 **********************************************************************/

# if defined (PDL_HAS_FALLOCATE)
#include <fcntl.h>
#endif

#include <idl.h>
#include <idu.h>
#include <ideErrorMgr.h>
#include <smDef.h>

double showElapsed( struct timeval *start_time, struct timeval *end_time);
double checkTime(struct timeval *sTime, struct timeval *eTime );

/******************************************************************************
 * Description : BUG-45292 truncate 함수를 이용하면 log 파일 생성 시간을 단축할수 있을듯 합니다. 
                 fallocate 를 사용하는데 환경에 따라 그냥 write 2번하는게 빠르기도 하다. 
                 이것을 확인하기 위한 테스트. 
 ******************************************************************************/
int main()
{
    UInt   sMode       = 0;
    UInt   sOffset     = 0; 
    ULong  sFileSize   = 1024*1024*1024;
    SChar *src  = (char*)calloc(sFileSize,1);
    SChar *addr = NULL;
    SInt   fd;   

    struct timeval startTime;
    struct timeval endTime;

    memset( src, 'Z', sFileSize );

# if defined (PDL_HAS_FALLOCATE)
    {
        printf("fallocate to expand file size to %luGB\n", sFileSize/1024/1024/1024);

        gettimeofday(&startTime, NULL);

        IDE_TEST_RAISE( (fd = open( "1Gf.out", O_RDWR | O_CREAT, 0777 )) < 0, open_error) ;
        IDE_TEST_RAISE( fallocate( fd, sMode, sOffset, sFileSize ) != 0, fallocate_error );
        close(fd);

        IDE_TEST_RAISE( (fd = open( "1Gf.out", O_RDWR )) < 0, open_error) ;
        IDE_TEST_RAISE( (addr = (char *) mmap( (void*)0, sFileSize, PROT_WRITE | PROT_READ, MAP_SHARED, fd, 0)) 
                        == (caddr_t)-1 ,mmap_error ); 
        
        memcpy( addr, src, sFileSize );
        close(fd);

        gettimeofday(&endTime, NULL);
        (void)checkTime(&startTime, &endTime);

        unlink("1Gf.out");
    }
#else
        idlOS::printf( "Warning : This system does not implement fallocate(). \n");
#endif
    {
        idlOS::printf("write to expand file size to %lluGB\n", sFileSize/1024/1024/1024);

        gettimeofday(&startTime, NULL);

        IDE_TEST_RAISE( (fd = open( "1Gw.out", O_RDWR | O_CREAT, 0777 )) < 0, open_error) ;
        write( fd, src, sFileSize );
        close(fd);

        IDE_TEST_RAISE( (fd = open( "1Gw.out", O_RDWR )) < 0, open_error) ;
        write( fd, src, sFileSize );
        close(fd);

        gettimeofday(&endTime, NULL);
        (void)checkTime(&startTime, &endTime);

        unlink("1Gw.out");
    }

    return IDE_SUCCESS;

    IDE_EXCEPTION( open_error )
    {
        idlOS::printf(" file open error [%d]\n",errno);
    }
    IDE_EXCEPTION( fallocate_error )
    {
        idlOS::printf( "Warning : The fallocate() is not supported by the filesystem(or kernel). \n ");
    } 
    IDE_EXCEPTION( mmap_error )
    {
        idlOS::printf("mmap error\n");
    }
    IDE_EXCEPTION_END;

    close(fd);
    unlink("1Gf.out");
    unlink("1Gw.out");

    return IDE_FAILURE;
}

/**********************************************************
** show time
**********************************************************/
double  showElapsed( struct timeval *start_time, struct timeval *end_time)
{
    struct timeval v_timeval;
    double elapsedtime ;

    v_timeval.tv_sec  = end_time->tv_sec  - start_time->tv_sec;
    v_timeval.tv_usec = end_time->tv_usec - start_time->tv_usec;

    if (v_timeval.tv_usec < 0)
    {
        v_timeval.tv_sec -= 1;
        v_timeval.tv_usec = 999999 - v_timeval.tv_usec * (-1);
    }

    elapsedtime = v_timeval.tv_sec*1000000+v_timeval.tv_usec;

    idlOS::printf(" Elapsed Time ==>       %10.3f seconds\n", elapsedtime/1000000.00);
    
    return elapsedtime ;
}

double checkTime(struct timeval *sTime, struct timeval *eTime )
{
    double elapsedtime;

    elapsedtime = showElapsed(sTime, eTime);
    return elapsedtime;
}
