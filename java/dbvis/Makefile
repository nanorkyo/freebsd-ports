PORTNAME=	dbvis
DISTVERSION=	13.0.4
CATEGORIES=	java databases
MASTER_SITES=	https://www.dbvis.com/product_download/${PORTNAME}-${PORTVERSION}/media/
DISTNAME=	dbvis_linux_${PORTVERSION:S/./_/g}

MAINTAINER=	jim@ohlste.in
COMMENT=	DbVisualizer database tool
WWW=		https://www.dbvis.com/

LICENSE=	DbVisualizer_EULA
LICENSE_NAME=	End-User License Agreement for DbVisualizer
LICENSE_TEXT=	Full license can be found at https://www.dbvis.com/eula/
# Redistribution is not permitted
LICENSE_PERMS=	auto-accept

USES=		java
JAVA_VENDOR=	openjdk

NO_BUILD=	yes

WRKSRC=		${WRKDIR}/DbVisualizer
PLIST_FILES=	bin/dbvis

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}
	cd ${STAGEDIR}${PREFIX}/bin && ${LN} -s ../share/dbvis/dbvis dbvis
	${CHMOD} a+x ${STAGEDIR}${DATADIR}/dbvis

post-install:
	${FIND} ${STAGEDIR}${DATADIR} -not -type d \
	  | ${SED} -ne 's,^${STAGEDIR}${PREFIX}/,,p' >> ${TMPPLIST}
	${FIND} -d ${STAGEDIR}${DATADIR} -type d -empty \
	  | ${SED} -ne 's,^${STAGEDIR}${PREFIX}/,@dir ,p' >> ${TMPPLIST}

.include <bsd.port.mk>
