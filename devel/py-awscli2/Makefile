PORTNAME=	awscli
DISTVERSION=	2.36.19
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	2

MAINTAINER=	nork@FreeBSD.org
COMMENT=	Universal Command Line Interface for Amazon Web Services V2
WWW=		https://aws.amazon.com/cli

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}awscrt>=0.35.0:devel/py-awscrt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}colorama>=0.2.5:devel/py-colorama@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}distro>=1.5.0:sysutils/py-distro@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docutils>=0.10:textproc/py-docutils@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flit-core>=3.12.0:devel/py-flit-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jmespath>=0.7.1:devel/py-jmespath@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}macholib>=1.16.3:devel/py-macholib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pip>=22.0.0<26.0.0:devel/py-pip@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}prompt-toolkit>=3.0.24:devel/py-prompt-toolkit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dateutil>=2.1:devel/py-python-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ruamel.yaml.clib>=0.2.0:devel/py-ruamel.yaml.clib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ruamel.yaml>=0.15.0:devel/py-ruamel.yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=3.8.13:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3>=1.25.4,1:net/py-urllib3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wcwidth>=0.2.8:devel/py-wcwidth@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0.46.3:devel/py-wheel@${PY_FLAVOR}

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}awscrt>=0.35.0:devel/py-awscrt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}colorama>=0.2.5:devel/py-colorama@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}distro>=1.5.0:sysutils/py-distro@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docutils>=0.10:textproc/py-docutils@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jmespath>=1.0.1:devel/py-jmespath@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}macholib>=1.16.3:devel/py-macholib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}prompt-toolkit>=3.0.24:devel/py-prompt-toolkit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dateutil>=2.1:devel/py-python-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ruamel.yaml.clib>=0.2.0:devel/py-ruamel.yaml.clib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ruamel.yaml>=0.15.0:devel/py-ruamel.yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=3.8.13:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3>=1.25.4,1:net/py-urllib3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wcwidth>=0.2.8:devel/py-wcwidth@${PY_FLAVOR}

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}attrs>=23.2.0:devel/py-attrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}coverage>=7.0.1:devel/py-coverage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonschema>=4.7.2:devel/py-jsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=24.1:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pip-tools>=7.5.3:devel/py-pip-tools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>=4.1.0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>=3.1.0:devel/py-pytest-xdist@${PY_FLAVOR}

USES=		python sqlite
USE_GITHUB=	yes
GH_ACCOUNT=	aws
GH_PROJECT=	aws-cli
USE_PYTHON=	autoplist pep517 pytest
TEST_ARGS=	-n auto --tb=long -W ignore::DeprecationWarning \
		--ignore=tests/unit/customizations/configure/test_sso.py \
		--ignore=tests/unit/customizations/wizard/test_app.py \
		--ignore=tests/unit/s3transfer/test_utils.py \
		tests/unit
TEST_ENV=	${MAKE_ENV:NXDG_*}

CONFLICTS=	awscli py*-awscli*
NO_ARCH=	yes
#SUB_FILES=	pkg-message

post-extract:
	@${RM} ${WRKSRC}/bin/aws.cmd

post-patch:
	@${REINPLACE_CMD} -i '' -e "s|%%PYTHON_CMD%%|${PYTHON_CMD}|" \
		${WRKSRC}/tests/unit/customizations/emr/test_emr_utils.py

.include <bsd.port.mk>
