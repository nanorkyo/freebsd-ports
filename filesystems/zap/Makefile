PORTNAME=	zap
DISTVERSION=	0.8.3
PORTREVISION=	1
CATEGORIES=	filesystems sysutils

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Maintain and replicate ZFS snapshots
WWW=		https://github.com/Jehops/zap

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	Jehops

NO_ARCH=	yes
NO_BUILD=	yes

USERS=		${PORTNAME}
GROUPS=		${PORTNAME}

PLIST_FILES=	bin/${PORTNAME} \
		share/man/man1/${PORTNAME}.1.gz
PORTDOCS=	README.org

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
