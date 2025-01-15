DIR := srcs
DOCKER_COMPOSE_YML := docker-compose.yml
DOCKER_COMPOSE_FLAGS := -f $(DIR)/$(DOCKER_COMPOSE_YML)

USER := tajeong

WP_VOLUME_DIR = ./home/$(USER)/data/wp
DB_VOLUME_DIR = ./home/$(USER)/data/db

NAME := inception

all:
	@ echo "[$@]"
	make db
	make wp
	# make build
	docker-compose $(DOCKER_COMPOSE_FLAGS) up -d --build

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

down:
	@ echo "[$@]"
	docker-compose $(DOCKER_COMPOSE_FLAGS) down

up:
	@ echo "[$@]"
	docker-compose $(DOCKER_COMPOSE_FLAGS) up -d

re:
	@ echo "[$@]"
	make fclean
	make all

clean:
	@ echo "[$@]"
	docker-compose $(DOCKER_COMPOSE_FLAGS) down

fclean:
	@ echo "[$@]"
	make clean
	docker-compose $(DOCKER_COMPOSE_FLAGS) down -v
	# rm -rf $(WP_VOLUME_DIR)
	rm -rf $(WP_VOLUME_DIR) $(DB_VOLUME_DIR)

