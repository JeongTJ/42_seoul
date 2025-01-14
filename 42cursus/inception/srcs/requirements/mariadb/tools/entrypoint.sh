#!/bin/bash
# set -e

TARGET_FILE="/run/mysqld/mysqld.sock"

if [ ! -d "/var/lib/mysql/$MYSQL_DATABASE_NAME" ]; then
mysql_install_db

mysqld &

while ! mysqladmin ping --silent; do
    echo "Waiting for MySQL to start..."
    sleep 1
done
echo "MySQL is running!"

mysql << EOF
CREATE USER '$MYSQL_USERNAME'@'$MYSQL_USER_HOSTNAME' IDENTIFIED BY '$MYSQL_PASSWORD';
GRANT ALL PRIVILEGES ON $MYSQL_DATABASE_NAME.* TO '$MYSQL_USERNAME'@'$MYSQL_USER_HOSTNAME';
CREATE DATABASE $MYSQL_DATABASE_NAME;
EOF
mysqladmin -u root -p shutdown

fi

mysqld 