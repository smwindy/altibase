/** 
 *  Copyright (c) 1999~2017, Altibase Corp. and/or its affiliates. All rights reserved.
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Affero General Public License, version 3,
 *  as published by the Free Software Foundation.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU Affero General Public License for more details.
 *
 *  You should have received a copy of the GNU Affero General Public License
 *  along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
 
#include <idl.h>


int main()
{
    SChar sTarget[10] = "Hello";
    SChar sBuf[]       = "World";

    idlVA::appendFormat(sTarget, ID_SIZEOF(sTarget), ", ");
    idlVA::appendString(sTarget, ID_SIZEOF(sTarget), sBuf, 4);

    idlOS::printf("%s\n", sTarget);

    return 0;
}
