##
## Makefile in /home/guerot_a/depots/PSU_2013_myscript
## 
## Made by anthony guerot
## Login   <guerot_a@epitech.net>
## 
## Started on  Sun Mar  2 18:06:05 2014 anthony guerot
## Last update Sat Apr  5 22:39:07 2014 
##

## FILES

NAME		=	lib_nibbler_caca.so

SRC		=	Renderer

SRC_EXT		=	.cpp

## DIRECTORIES

DOBJ		=	obj
DSRC		=	src
DBIN		=	bin

## COMPILATION

DINC		=	include				\
			template			\
			../shared/include

CFLAGS		=	-Wall		\
			-Wextra		\
			`caca-config --cflags`

## LINKAGE

LIB		=

DLIB		=

LDFLAGS		=	`caca-config --libs`

## RUNS

CC		=	g++ -fmax-errors=2
RM		=	rm -rf
MD		=	mkdir -p

####################
## INTERNAL RULES ##
####################

## CONSTANTS

DBGBOOL		=	yes

DBG		=	-g3		\
			-ggdb

WERROR		=	-Werror

## FILES

OBJ		=	$(addsuffix .o, $(SRC))
_SRC		=	$(addsuffix $(SRC_EXT), $(SRC))

## DIRECTORIES

DINC		:=	$(addsuffix /, $(DINC))
DOBJ		:=	$(addsuffix /, $(DOBJ))
DSRC		:=	$(addsuffix /, $(DSRC))
DBIN		:=	$(addsuffix /, $(DBIN))

## COMPILATION ARGS

CINC		=	$(addprefix -I, $(DINC))

COBJ		=	$(addprefix $(DOBJ), $(OBJ))
CSRC		=	$(addprefix $(DSRC), $(_SRC))
CNAME		=	$(addprefix $(DBIN), $(NAME))

## LINKAGE ARGS

LIB		:=	$(addprefix -l, $(LIB))
DLIB		:=	$(addsuffix /, $(DLIB))
DLIB		:=	$(addprefix -L, $(DLIB))

## FLAGS

ifeq ($(DBGBOOL), yes)
	CFLAGS  += $(DBG)
endif

ifeq ($(DBGBOOL), no)
	CFLAGS	+= $(WERROR)
endif

CFLAGS		+=	$(CINC)
LDFLAGS		+=	$(DLIB)		\
			$(LIB)

## MISC RULES

MAKEOBJ		= $(addprefix $(DOBJ), %.o) : $(addprefix $(addprefix $(DSRC), %), $(SRC_EXT))

all:	$(CNAME)

dbg:	$(CNAME)

$(CNAME):	$(COBJ)
		@$(MD) $(DBIN)
		@echo "Linkage : $(CNAME)"
		@$(CC) -shared $(COBJ) -o $(CNAME) $(LDFLAGS)

$(COBJ):	$(MAKEOBJ)
		@$(MD) $(DOBJ)
		@for dir in `cd $(DSRC); ls -d */ 2> /dev/null`; \
		do \
		if [ ! -d "$(DOBJ)$$dir" ];then \
			$(MD) $(DOBJ)$$dir; \
		fi \
		done
		@echo "Compilation : $<"
		@$(CC) -fPIC -c $< -o $@ $(CFLAGS)

clean:
		@echo "Deleting obj files"
		@$(RM) $(COBJ)

fclean:		clean
		@echo "Deleting executable"
		@$(RM) $(CNAME)

re:		fclean all
redbg:		fclean dbg

.PHONY:		fclean clean all dbg re
