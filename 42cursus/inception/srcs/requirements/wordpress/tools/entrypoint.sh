#!/bin/bash
set -e

WP_PATH="/home/tajeong/data/wordpress_files"

if [ ! -d $WP_PATH ]; then
  echo "non exist wp"
  wp core download --path=$WP_PATH --allow-root
else
  echo "exist wp"
fi

while [ ! -e $WP_PATH ]; do
	echo "$TARGET_FILE"
    echo "Waiting for $TARGET_FILE to be created..."
    sleep 1  # 1초 대기
done

# cd $WP_PATH

# wp config create --dbname=wp_db --dbuser=tajeong-root --dbpass=1234 --dbhost=wordpress.docker-network --allow-root
wp config create --dbname=$MYSQL_DATABASE_NAME --dbuser=$MYSQL_ROOT_USERNAME --dbpass=$MYSQL_ROOT_PASSWORD --dbhost=$MYSQL_HOSTNAME --allow-root
# wp db create --allow-root
# wp core install --url=wpclidemo.dev --title="WP-CLI" --admin_user=tajeong --admin_password=1234 --admin_email=dmswl022329@gmail.com --allow-root

# cd $HOME

php-fpm7.4 --nodaemonize