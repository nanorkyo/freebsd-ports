PORTNAME=	Flask-SAML
PORTVERSION=	0.5.1
PORTREVISION=	3
CATEGORIES=	security www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	john@saltant.com
COMMENT=	SAML authentication for Flask web apps
WWW=		https://bitbucket.org/asecurityteam/flask_saml

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}blinker>=1.1:devel/py-blinker@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flask>=0.8.0:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pysaml2>=6.5.0:security/py-pysaml2@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
