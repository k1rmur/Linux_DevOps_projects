FROM ubuntu

RUN groupadd -g 1000 appgroup && \
    useradd -u 1000 -g appgroup -m -s /bin/bash appuser

USER root

RUN apt-get update && \
    apt-get install -y gcc spawn-fcgi libfcgi-dev nginx && \
    rm -rf /var/lib/apt/lists

RUN mkdir /app && \
    chown -R appuser:appgroup /app /var /run /etc/nginx && \
    chmod -R 755 /app 

USER appuser

WORKDIR /app

COPY ./nginx.conf /etc/nginx/./
COPY server.c .

CMD gcc -o fcgi server.c -lfcgi && spawn-fcgi -p  8080 fcgi && nginx -g 'daemon off;' && nginx -s reload