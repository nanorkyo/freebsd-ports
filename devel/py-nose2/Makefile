PORTNAME=	nose2
PORTVERSION=	0.10.0
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	daniel@blodan.se
COMMENT=	Next generations of nicer testing for Python
WWW=		https://nose2.readthedocs.io

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/license.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}coverage>=4.4.1:devel/py-coverage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.7:devel/py-six@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

TEST_ENV=	PYTHONPATH=${WRKSRC}

do-test:
	@cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m nose2.__main__ -v --pretty-assert

.include <bsd.port.mk>
