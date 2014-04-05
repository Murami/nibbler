##
## Makefile for  in /home/guerot_a/rendu/cpp_nibbler
## 
## Made by guerot_a
## Login   <guerot_a@epitech.net>
## 
## Started on  Wed Mar 26 17:33:20 2014 guerot_a
## Last update Sat Apr  5 22:38:43 2014 
##

all:	core sfml opengl libcaca

core:
	@echo "[core]"
	@make -s -C core/
	@echo "Copie des binaires"
	@cp -f core/bin/* .
	@echo " "

sfml:
	@echo "[API SFML]"
	@make -s -C sfml/
	@echo "Copie des binaires"
	@cp -f sfml/bin/* .
	@echo " "

opengl:
	@echo "[API OpenGL]"
	@make -s -C opengl/
	@echo "Copie des binaires"
	@cp -f opengl/bin/* .
	@echo " "

libcaca:
	@echo "[API @%&#é]"
	make -s -C libcaca/
	@echo "Copie des binaires"
	@cp -f libcaca/bin/* .
	@echo " "

clean:
	@echo "[core]"
	@make -s clean -C core/
	@echo " "
	@echo "[API SFML]"
	@make -s clean -C sfml/
	@echo " "
	@echo "[API OpenGL]"
	@make -s clean -C opengl/
	@echo " "
	@echo "[API @%&#é]"
	@make -s clean -C libcaca/
	@echo " "

fclean:
	@echo "[core]"
	@make -s fclean -C core/
	@echo " "
	@echo "[API SFML]"
	@make -s fclean -C sfml/
	@echo " "
	@echo "[API OpenGL]"
	@make -s fclean -C opengl/
	@echo " "
	@echo "[API @%&#é]"
	@make -s fclean -C libcaca/
	@echo " "
	@rm -rf nibbler lib_nibbler_sfml16.so
	@rm -rf nibbler lib_nibbler_opengl.so
	@rm -rf nibbler lib_nibbler_caca.so

re:	fclean all

.PHONY:	all clean fclean re sfml core opengl libcaca
