PORTNAME=	jsondiff
PORTVERSION=	2.0.0
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Diff JSON and JSON-like structures in Python
WWW=		https://github.com/xlwings/jsondiff

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

CONFLICTS_INSTALL=	jojodiff py*-jsonpatch # bin/jdiff

NO_ARCH=	yes

.include <bsd.port.mk>
