PORTNAME=	aspell
PORTVERSION=	0.60.8.1
CATEGORIES=	textproc
MASTER_SITES=	GNU/aspell
PKGNAMESUFFIX=	-ispell

MAINTAINER=	office@FreeBSD.org
COMMENT=	Ispell compatibility script for aspell
WWW=		http://aspell.net/

LICENSE=	LGPL21

RUN_DEPENDS=	aspell:textproc/aspell

USES=		cpe
CPE_VENDOR=	gnu

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/ispell \
		bin/spell

post-patch:
	@${REINPLACE_CMD} -e '/^#CHECK_FLAGS/ s|#||' ${WRKSRC}/scripts/ispell

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/ispell ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/spell ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
