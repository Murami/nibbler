##
## Makefile for  in /home/guerot_a/rendu/cpp_nibbler
## 
## Made by guerot_a
## Login   <guerot_a@epitech.net>
## 
## Started on  Wed Mar 26 17:33:20 2014 guerot_a
## Last update Thu Mar 27 13:43:30 2014 guerot_a
##

all:	core sfml

core:
	@echo "[core]"
	@make -s -C core/
	@echo "Copie des binaires dans bin/"
	@cp -f core/bin/* bin/
	@echo " "

sfml:
	@echo "[API SFML]"
	@make -s -C sfml/
	@echo "Copie des binaires dans bin/"
	@cp -f sfml/bin/* bin/
	@echo " "

opengl:
	@echo "[API OpenGL]"
	@make -s -C opengl/
	@echo "Copie des binaires dans bin/"
	@cp -f opengl/bin/* bin/
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
	@rm -rf bin/*

re:	fclean all

.PHONY:	all clean fclean re opengl sfml core
