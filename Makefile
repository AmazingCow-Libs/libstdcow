##----------------------------------------------------------------------------##
##               █      █                                                     ##
##               ████████                                                     ##
##             ██        ██                                                   ##
##            ███  █  █  ███        Makefile                                  ##
##            █ █        █ █        libstdcow                                 ##
##             ████████████                                                   ##
##           █              █       Copyright (c) 2016                        ##
##          █     █    █     █      AmazingCow - www.AmazingCow.com           ##
##          █     █    █     █                                                ##
##           █              █       N2OMatt - n2omatt@amazingcow.com          ##
##             ████████████         www.amazingcow.com/n2omatt                ##
##                                                                            ##
##                  This software is licensed as GPLv3                        ##
##                 CHECK THE COPYING FILE TO MORE DETAILS                     ##
##                                                                            ##
##    Permission is granted to anyone to use this software for any purpose,   ##
##   including commercial applications, and to alter it and redistribute it   ##
##               freely, subject to the following restrictions:               ##
##                                                                            ##
##     0. You **CANNOT** change the type of the license.                      ##
##     1. The origin of this software must not be misrepresented;             ##
##        you must not claim that you wrote the original software.            ##
##     2. If you use this software in a product, an acknowledgment in the     ##
##        product IS HIGHLY APPRECIATED, both in source and binary forms.     ##
##        (See opensource.AmazingCow.com/acknowledgment.html for details).    ##
##        If you will not acknowledge, just send us a email. We'll be         ##
##        *VERY* happy to see our work being used by other people. :)         ##
##        The email is: acknowledgment_opensource@AmazingCow.com              ##
##     3. Altered source versions must be plainly marked as such,             ##
##        and must not be misrepresented as being the original software.      ##
##     4. This notice may not be removed or altered from any source           ##
##        distribution.                                                       ##
##     5. Most important, you must have fun. ;)                               ##
##                                                                            ##
##      Visit opensource.amazingcow.com for more open-source projects.        ##
##                                                                            ##
##                                  Enjoy :)                                  ##
##----------------------------------------------------------------------------##

#################################################################################
## COWTODO: Note to myself:                                                    \
##			The projects are getting bigger and my make stills is very limited \
## 	        Get a book quickly and study make :O - NOWWWW.
################################################################################


## COWTODO: This vars **ARE VERY SHIT** - Get a make book and study
## COWNOTE: Does the jobs - Is not the correct way but...
NDEBUG            = -DNDEBUG
STDCOWTESTENABLED = -DAMAZINGCOW_LIBSTDCOW_SHOWCASE_TEST_ENABLED
INCLUDE           = -I./include/
SRC               = ./src
TESTSRC           = ./test

CC 	= gcc $(NONSTRIPPED) $(NDEBUG) $(INCLUDE)

#Create the object files and the executable test
all: obj bin

#Clean up the stuff generate by obj and bin targets.
clean:
	rm -rf ./obj
	rm -rf ./bin

#Create the object files for libstdcow.
obj:
	mkdir -p ./obj

	$(CC) -c ./src/*.c

	mv *.o ./obj/

#Create a test executable
bin:
	mkdir -p ./bin

	$(CC) $(STDCOWTESTENABLED) $(SRC)/*.c $(TESTSRC)/*.c  -o ./bin/test
