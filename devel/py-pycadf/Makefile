PORTNAME=	pycadf
PORTVERSION=	4.0.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	CADF Library
WWW=		https://docs.openstack.org/pycadf/latest/ \
		https://github.com/openstack/pycadf

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=2.0.0:devel/py-pbr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}oslo.config>=5.2.0:devel/py-oslo.config@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.serialization>=2.18.0:devel/py-oslo.serialization@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pbr>=2.0.0:devel/py-pbr@${PY_FLAVOR}

USES=		cpe python:3.9+
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

CPE_VENDOR=	openstack

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
.for service in cinder glance gnocchi heat ironic neutron nova swift trove
	${INSTALL_DATA} ${WRKSRC}/etc/pycadf/${service}_api_audit_map.conf ${STAGEDIR}${ETCDIR}/${service}_api_audit_map.conf.sample
.endfor

.include <bsd.port.mk>
