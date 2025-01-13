#!/bin/bash
set -e

# WP_PATH="/home/tajeong/data"
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

while [ ! -d "$TARGET_FILE1" ] || [ ! -d "$TARGET_FILE2" ] || [ ! -d "$TARGET_FILE3" ]; do
    echo "Waiting for $TARGET_FILE to be created..."
    sleep 1
done

# wp config create --dbname=wp_db --dbuser=tajeong-root --dbpass=1234 --dbhost=wordpress.docker-network --allow-root
if [ ! -f "$CONFIG_FILE" ]; then
	wp config create --dbname=$MYSQL_DATABASE_NAME --dbuser=$MYSQL_ROOT_USERNAME --dbpass=$MYSQL_ROOT_PASSWORD --dbhost=$MYSQL_HOSTNAME --allow-root
fi

wp core install --url=localhost --title="tajeong's homepage" --admin_user=tajeong --admin_password=1234 --admin_email=dmswl022329@gmail.com --allow-root

# wp plugin update --all --allow-root
# wp super-admin add wpcli --allow-root
# wp media regenerate --yes --allow-root

chown -R www-data:www-data /var/www/html/
chmod -R 755 /var/www/html/

php-fpm7.4 --nodaemonize