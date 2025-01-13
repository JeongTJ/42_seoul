FROM debian:bullseye

# MariaDB 설치
RUN apt update -y
RUN apt install -y mariadb-server mariadb-client

# # 데이터 디렉터리 초기화
# RUN mysql_install_db --user=mysql --ldata=/var/lib/mysql

RUN mkdir -p /run/mysqld
RUN chown -R mysql:mysql /run/mysqld

COPY ./conf/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf

COPY ./tools/entrypoint.sh /entrypoint.sh
RUN chmod +x /entrypoint.sh

# 컨테이너 실행 시 MariaDB 시작
ENTRYPOINT ["/entrypoint.sh"]