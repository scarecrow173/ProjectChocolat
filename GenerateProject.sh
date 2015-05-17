#!/bin/sh
cd `dirname $0`
`dirname $0`/Tools/premake/Mac/premake4 xcode4
#`dirname $0`/Tools/premake/Mac/premake4 gmake
make -j8