PORTNAME=	qmasm
DISTVERSIONPREFIX=	v
DISTVERSION=	4.1
PORTREVISION=	2
CATEGORIES=	lang

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Quantum macro assembler for D-Wave systems
WWW=		https://github.com/lanl/qmasm

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}PuLP>0:math/py-PuLP@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	lanl
USE_PYTHON=	distutils noflavors autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
