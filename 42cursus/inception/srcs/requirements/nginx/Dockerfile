FROM debian:bullseye

RUN apt-get update
RUN apt-get install nginx -y
RUN apt-get install openssl -y

COPY ./conf/nginx.conf /etc/nginx/nginx.conf
COPY ./tools/entrypoint.sh /entrypoint.sh

RUN mkdir -p /etc/nginx/ssl

RUN chmod +x /entrypoint.sh

ENTRYPOINT [ "/entrypoint.sh" ]