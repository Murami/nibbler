##
## Makefile for  in /home/guerot_a/rendu/cpp_nibbler
## 
## Made by guerot_a
## Login   <guerot_a@epitech.net>
## 
## Started on  Wed Mar 26 17:33:20 2014 guerot_a
## Last update Thu Apr  3 15:29:54 2014 guerot_a
##

all:	core sfml opengl

core:
	@echo "[core]"
	@make -s -C core/
	@echo "Copie des binaires dans bin/"
	@cp -f core/bin/* .
	@echo " "

sfml:
	@echo "[API SFML]"
	@make -s -C sfml/
	@echo "Copie des binaires dans bin/"
	@cp -f sfml/bin/* .
	@echo " "

opengl:
	@echo "[API OpenGL]"
	@make -s -C opengl/
	@echo "Copie des binaires dans bin/"
	@cp -f opengl/bin/* .
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
	@rm -rf nibbler lib_nibbler_sfml16.so
	@rm -rf nibbler lib_nibbler_opengl.so

re:	fclean all

.PHONY:	all clean fclean re sfml core opengl
