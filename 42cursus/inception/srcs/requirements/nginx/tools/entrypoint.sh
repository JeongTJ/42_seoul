#!/bin/bash

if [ ! -f /etc/nginx/ssl/selfsigned.key ] || [ ! -f /etc/nginx/ssl/selfsigned.crt ]; then
	openssl req \
		-x509 \
		-nodes \
		-days 365 \
		-newkey rsa:2048 \
		-keyout /etc/nginx/ssl/selfsigned.key \
		-out /etc/nginx/ssl/selfsigned.crt \
		-subj "/C=KR/ST=Seoul/L=Gaepodong/O=42Seoul/CN=tajeong.42.fr"
fi

nginx
