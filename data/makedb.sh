#!/bin/sh

rm -f part.db
touch part.db
../db/DbLoader part.db STD0805 < TmpPart.p1
../db/DbLoader part.db STDR025 < TmpPart.p2
../db/DbLoader part.db PA001 < TmpPart.p3
../db/DbLoader part.db PA002 < TmpPart.p4
../db/DbLoader part.db PA003 < TmpPart.p5
../db/DbLoader part.db PA004 < TmpPart.p6
../db/DbLoader part.db PA005 < TmpPart.p7
../db/DbLoader part.db HEAD < Header.pg
../db/DbLoader part.db TAIL < Footer.pg

