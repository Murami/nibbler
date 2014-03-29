##
## Makefile for  in /home/guerot_a/rendu/cpp_nibbler
## 
## Made by guerot_a
## Login   <guerot_a@epitech.net>
## 
## Started on  Wed Mar 26 17:33:20 2014 guerot_a
## Last update Sat Mar 29 22:43:54 2014 guerot_a
##

all:	core sfml

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

clean:
	@echo "[core]"
	@make -s clean -C core/
	@echo " "
	@echo "[API SFML]"
	@make -s clean -C sfml/
	@echo " "

fclean:
	@echo "[core]"
	@make -s fclean -C core/
	@echo " "
	@echo "[API SFML]"
	@make -s fclean -C sfml/
	@echo " "
	@rm -rf nibbler lib_nibbler_sfml16.so

re:	fclean all

.PHONY:	all clean fclean re sfml core
