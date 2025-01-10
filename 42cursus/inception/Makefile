DIR := srcs
DOCKER_COMPOSE_YML := docker-compose.yml
DOCKER_COMPOSE_FLAGS := -f $(DIR)/$(DOCKER_COMPOSE_YML)

USER := tajeong

WP_VOLUME_DIR = ./home/$(USER)/data/wp
DB_VOLUME_DIR = ./home/$(USER)/data/db

NAME := inception

all: wp db build
	@ echo "[$@]"
	docker-compose $(DOCKER_COMPOSE_FLAGS) up -d

restart:
	@ echo "[$@]"
	docker-compose $(DOCKER_COMPOSE_FLAGS) restart


wp:
	@ echo "[$@]"
	mkdir -p $(WP_VOLUME_DIR)

db:
	@ echo "[$@]"
	mkdir -p $(DB_VOLUME_DIR)

build:
	@ echo "[$@]"
	docker-compose $(DOCKER_COMPOSE_FLAGS) build

exec:
	@ echo "[$@]"
	docker container exec -it $(CONT) bash

logs:
	@ echo "[$@]"
	docker-compose $(DOCKER_COMPOSE_FLAGS) logs $(CONT)

re: fclean all
	@ echo "[$@]"
	@ echo re

clean:
	@ echo "[$@]"
	docker-compose $(DOCKER_COMPOSE_FLAGS) down -v

fclean:
	@ echo "[$@]"
	rm -rf $(WP_VOLUME_DIR) $(DB_VOLUME_DIR)
	make clean

