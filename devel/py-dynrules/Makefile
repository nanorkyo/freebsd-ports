PORTNAME=	dynrules
PORTVERSION=	0.1.0
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	http://bitbucket.org/marcusva/py-dynrules/downloads/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Dynamic Scripting for adaptive AI systems
WWW=		https://bitbucket.org/marcusva/py-dynrules

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/doc/copying.rst

USES=		python
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/html
	@${TAR} -C ${WRKSRC}/doc/html -cf - . | \
		${TAR} -C ${STAGEDIR}${DOCSDIR}/html -xf -

.include <bsd.port.mk>
