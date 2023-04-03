NAME = philo
BNAME = philo_bonus

LIB = lib$(NAME).a
BLIB = lib$(BNAME).a

MAIN = philo.c
BMAIN = philo_bonus.c

SOURCES = \
		check_args.c set_dinner.c set_phils.c dining.c get_time.c utils.c\

BSOURCES = \
		check_args_bonus.c set_phils_bonus.c dining_bonus.c get_time_bonus.c utils_bonus.c exit_status_bonus.c\

DIR = ./philo
BDIR = ./philo_bonus

DIRNAME = $(addprefix $(DIR)/, $(NAME))
DIRBNAME = $(addprefix $(BDIR)/, $(BNAME))

DIRLIB = $(addprefix $(DIR)/, $(LIB))
DIRBLIB = $(addprefix $(BDIR)/, $(BLIB))

DIRMAIN = $(addprefix $(DIR)/, $(MAIN))
DIRBMAIN = $(addprefix $(BDIR)/, $(BMAIN))

DIRSRC = $(addprefix $(DIR)/, $(SOURCES))
DIRBSRC = $(addprefix $(BDIR)/, $(BSOURCES))

DIRMAINOBJ = $(DIRMAIN:.c=.o)
DIRBMAINOBJ = $(DIRBMAIN:.c=.o)

DIROBJ = $(DIRSRC:.c=.o)
DIRBOBJ = $(DIRBSRC:.c=.o)

CC = gcc
CFLAGS = -g -Wall -Wextra -Werror
LIBS = -L$(DIR) -l$(NAME)
BLIBS = -L$(BDIR) -l$(BNAME)

all: $(NAME)

$(NAME): $(DIRMAINOBJ) $(DIROBJ)
	ar -rcs $(DIRLIB) $(DIROBJ)
	$(CC) -o $(DIRNAME) $(CFLAGS) $(DIRMAINOBJ) $(LIBS)

bonus: $(BNAME)

$(BNAME): $(DIRBMAINOBJ) $(DIRBOBJ)
	ar -rcs $(DIRBLIB) $(DIRBOBJ)
	$(CC) -o $(DIRBNAME) $(CFLAGS) $(DIRBMAINOBJ) $(BLIBS)

%.o: %.c
	$(CC) -c $(CFLAGS) $? -o $@

clean:
	rm -f $(DIRLIB) $(DIRMAINOBJ) $(DIROBJ) $(DIRBLIB) $(DIRBMAINOBJ) $(DIRBOBJ)

fclean: clean
	rm -f $(DIRNAME) $(DIRBNAME)

re: fclean
	make -B

.PHONY: all bonus clean fclean re
