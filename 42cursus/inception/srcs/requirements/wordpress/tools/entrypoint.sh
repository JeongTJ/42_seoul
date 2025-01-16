#!/bin/bash
set -e

WORDPRESS_DIR="/var/www/html"

TARGET_FILE1="${WORDPRESS_DIR}/wp-admin"
TARGET_FILE2="${WORDPRESS_DIR}/wp-content"
TARGET_FILE3="${WORDPRESS_DIR}/wp-includes"
CONFIG_FILE="${WORDPRESS_DIR}/wp-config.php"

cd ${WORDPRESS_DIR}

if [ ! -d "$TARGET_FILE1" ] || [ ! -d "$TARGET_FILE2" ] || [ ! -d "$TARGET_FILE3" ]; then
  echo "non exist wp"
  wp core download --path=${WORDPRESS_DIR} --allow-root
else
  echo "exist wp"
fi

if [ ! -f "$CONFIG_FILE" ]; then
	wp config create --dbname=$MYSQL_DATABASE_NAME --dbuser=$MYSQL_USERNAME --dbpass=$MYSQL_PASSWORD --dbhost=$MYSQL_HOSTNAME --allow-root
	wp core install --url=$DOMAIN_URL --title="$WORDPRESS_TITLE" --admin_user=$WORDPRESS_ADMIN_USERNAME --admin_password=$WORDPRESS_ADMIN_PASSWORD --admin_email=$WORDPRESS_ADMIN_EMAIL --allow-root
	wp user create $WORDPRESS_USERNAME $WORDPRESS_EMAIL --user_pass=$WORDPRESS_PASSWORD --role=author --allow-root
	wp theme install twentysixteen --activate --allow-root
	chown -R www-data:www-data $WORDPRESS_DIR
	chmod -R 755 $WORDPRESS_DIR
fi


php-fpm7.4 --nodaemonize
