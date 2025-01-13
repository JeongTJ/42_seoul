#!/bin/bash

TARGET_FILE="${WORDPRESS_DIR}/license.txt"

openssl req \
	-x509 \
	-nodes \
	-days 365 \
	-newkey rsa:2048 \
	-keyout /etc/nginx/ssl/selfsigned.key \
	-out /etc/nginx/ssl/selfsigned.crt \
	-subj "/C=KR/ST=Seoul/L=Gaepodong/O=42Seoul/CN=tajeong.42.fr"

# while [ ! -f $TARGET_FILE ]; do
#     echo "Waiting for $TARGET_FILE to be created..."
#     sleep 1  # 1초 대기
# done
# chown -R www-data:www-data /etc/nginx/ssl/selfsigned.key
# chown -R www-data:www-data /etc/nginx/ssl/selfsigned.crt
# chown -R 755 /etc/nginx/ssl/selfsigned.key
# chown -R 755 /etc/nginx/ssl/selfsigned.crt

nginx