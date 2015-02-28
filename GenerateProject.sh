#!/bin/sh
Tools/premake/Mac/premake4 xcode4
Tools/premake/Mac/premake4 gmake
make -j8