FROM debian:bullseye

# MariaDB 설치
RUN apt update && apt install -y mariadb-server mariadb-client

# 데이터 디렉터리 초기화
RUN mysql_install_db --user=mysql --ldata=/var/lib/mysql

# 소켓 디렉터리 생성 (에러 방지)
RUN mkdir -p /run/mysqld && chown mysql:mysql /run/mysqld

COPY ./conf/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf

# 컨테이너 실행 시 MariaDB 시작
CMD ["mysqld"]