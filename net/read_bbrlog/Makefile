PORTNAME=	read_bbrlog
PORTVERSION=	1.4
DISTVERSIONPREFIX=	v
CATEGORIES=	net

MAINTAINER=	olivier@FreeBSD.org
COMMENT=	Decode BBR log dumps generated with tcplog_dumper
WWW=		https://github.com/Netflix/read_bbrlog

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64

BUILD_DEPENDS=	${PREFIX}/include/bbparse.h:devel/bbparse

USE_GITHUB=	yes
GH_ACCOUNT=	Netflix

PLIST_FILES=	bin/read_bbrlog \
		share/man/man1/read_bbrlog.1.gz

CFLAGS+=	-I${PREFIX}/include
LDFLAGS+=	-L${PREFIX}/lib
MAKE_ENV+=	WITHOUT_PIE=true

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1500025
IGNORE=	builds only on FreeBSD head with minimum version 1500025
.endif

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/read_bbrlog ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/read_bbrlog.1.gz ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
