FROM nginx

RUN apt-get update && \
    apt-get install -y gcc spawn-fcgi libfcgi-dev nginx && \
    rm -rf /var/lib/apt/lists

COPY ./nginx.conf /etc/nginx/./
COPY server.c .

CMD gcc -o fcgi server.c -lfcgi && spawn-fcgi -p  8080 fcgi && nginx -g 'daemon off;' && nginx -s reload
