FROM debian:bullseye

RUN apt update -y

RUN apt install wget -y
# RUN apt install dump-init -y
RUN apt install php php-fpm libapache2-mod-php php-pear php-cgi php-common php-mbstring php-zip php-net-socket php-gd php-xml-util php-mysql php-bcmath unzip git -y

RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
RUN chmod +x wp-cli.phar
RUN mv wp-cli.phar /usr/local/bin/wp

RUN mkdir -p /run/php
RUN mkdir -p /home/tajeong/data

COPY ./tools/entrypoint.sh /entrypoint.sh

RUN chmod +x ./entrypoint.sh

ENTRYPOINT [ "/entrypoint.sh" ]
# ENTRYPOINT [ "/usr/bin/dumb-init" ,"--", "/entrypoint.sh" ]