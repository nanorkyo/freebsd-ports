PORTNAME=	pytanque
DISTVERSION=	1.1.0
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Petanque static python bindings
WWW=		https://github.com/quarkslab/arybo/tree/master/petanque

LICENSE=	BSD3CLAUSE

BROKEN_riscv64=	ld: error: lto.tmp: cannot link object files with different floating-point ABI

BUILD_DEPENDS=	pybind11>0:devel/pybind11

USES=		compiler:c++14-lang localbase python
USE_PYTHON=	distutils autoplist

post-extract:
	${RM} -r ${WRKSRC}/third-party/pybind11

.include <bsd.port.mk>
