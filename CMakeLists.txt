cmake_minimum_required(VERSION 3.13)
project(get_next_line C)

#set(CMAKE_C_STANDARD 11)
set (CMAKE_C_FLAGS_DEBUG  "${CMAKE_C_FLAGS_DEBUG} -fsanitize=address -fno-omit-frame-pointer -g")

include_directories(.)
include_directories(sources)

add_executable(get_next_line
        sources/ft_atoi.c
        sources/ft_bzero.c
        sources/ft_cpyuntil.c
        sources/ft_isalnum.c
        sources/ft_isalpha.c
        sources/ft_isascii.c
        sources/ft_isblank.c
        sources/ft_isdigit.c
        sources/ft_isprint.c
        sources/ft_itoa.c
        sources/ft_lstadd.c
        sources/ft_lstaddback.c
        sources/ft_lstdel.c
        sources/ft_lstdelone.c
        sources/ft_lstiter.c
        sources/ft_lstmap.c
        sources/ft_lstnew.c
        sources/ft_memalloc.c
        sources/ft_memccpy.c
        sources/ft_memchr.c
        sources/ft_memcmp.c
        sources/ft_memcpy.c
        sources/ft_memdel.c
        sources/ft_memmove.c
        sources/ft_memset.c
        sources/ft_putchar.c
        sources/ft_putchar_fd.c
        sources/ft_putendl.c
        sources/ft_putendl_fd.c
        sources/ft_putnbr.c
        sources/ft_putnbr_fd.c
        sources/ft_putstr.c
        sources/ft_putstr_fd.c
        sources/ft_strcat.c
        sources/ft_strchr.c
        sources/ft_strclr.c
        sources/ft_strcmp.c
        sources/ft_strcpy.c
        sources/ft_strdel.c
        sources/ft_strdup.c
        sources/ft_strequ.c
        sources/ft_striter.c
        sources/ft_striteri.c
        sources/ft_strjoin.c
        sources/ft_strjoinch.c
        sources/ft_strlcat.c
        sources/ft_strlen.c
        sources/ft_strmap.c
        sources/ft_strmapi.c
        sources/ft_strncat.c
        sources/ft_strncmp.c
        sources/ft_strncpy.c
        sources/ft_strnequ.c
        sources/ft_strnew.c
        sources/ft_strnlen.c
        sources/ft_strnstr.c
        sources/ft_strrchr.c
        sources/ft_strsplit.c
        sources/ft_strstr.c
        sources/ft_strsub.c
        sources/ft_strtrim.c
        sources/ft_swap.c
        sources/ft_tolower.c
        sources/ft_toupper.c
        sources/libft.h
        get_next_line.c
        get_next_line.h sources/ft_is_null_ptr.c sources/ft_strjoinf.c)
