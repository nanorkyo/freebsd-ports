PORTNAME=	routino
DISTVERSION=	3.4.3
CATEGORIES=	astro
MASTER_SITES=	http://www.routino.org/download/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Router for OpenStreetMap Data
WWW=		https://www.routino.org/

LICENSE=	AGPLv3

USES=		compiler gmake perl5 tar:tgz
USE_LDCONFIG=	yes

CONFLICTS_INSTALL=	jabberd # bin/router

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} 's|doc/routino|share/doc/routino|' \
		${WRKSRC}/Makefile.conf
	${REINPLACE_CMD} 's|gcc|${CC}|' \
		${WRKSRC}/Makefile.conf

post-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC}/web && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR} \
		"! -name Makefile")
	${RM} ${STAGEDIR}${PREFIX}/lib/libroutino*.so
	${RM} ${STAGEDIR}${PREFIX}/lib/libroutino*.so.0
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lib*
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*
	${STRIP_CMD} ${STAGEDIR}${WWWDIR}/bin/*
.for f in routino.so.0.0.0 routino-slim.so.0.0.0
	${LN} -sf lib${f} ${STAGEDIR}${PREFIX}/lib/lib${f:R:R}
	${LN} -sf lib${f:R:R} ${STAGEDIR}${PREFIX}/lib/lib${f:R:R:R}
.endfor

.include <bsd.port.mk>
