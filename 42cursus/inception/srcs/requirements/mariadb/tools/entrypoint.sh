#!/bin/bash
set -e

TARGET_FILE="/run/mysqld/mysqld.sock"

mysqld &

while [ ! -e "$TARGET_FILE" ]; do
	echo "$TARGET_FILE"
    echo "Waiting for $TARGET_FILE to be created..."
    sleep 1  # 1초 대기
done

mysql << EOF
CREATE USER '$MYSQL_ROOT_USERNAME'@'$MYSQL_HOSTNAME' IDENTIFIED BY '$MYSQL_ROOT_PASSWORD';
CREATE USER '$MYSQL_USERNAME'@'$MYSQL_HOSTNAME' IDENTIFIED BY '$MYSQL_PASSWORD';
GRANT ALL PRIVILEGES ON $MYSQL_DATABASE_NAME.* TO '$MYSQL_ROOT_USERNAME'@'$MYSQL_HOSTNAME';
GRANT ALL PRIVILEGES ON $MYSQL_DATABASE_NAME.* TO '$MYSQL_USERNAME'@'$MYSQL_HOSTNAME';
EOF

mysqladmin -u root -p shutdown

mysqld 