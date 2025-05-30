PORTNAME=	pyfda
PORTVERSION=	0.1
PORTREVISION=	14
DISTVERSIONSUFFIX=	rc6
CATEGORIES=	cad python devel
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	GUI tool for designing and analysing discrete time filters
WWW=		https://github.com/chipmuenk/pyFDA

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}docutils>0:textproc/py-docutils@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR}

USES=		python pyqt:5
USE_PYTHON=	distutils autoplist
USE_PYQT=	pyqt5:run
NO_ARCH=	yes

post-extract:
	@${MV} ${WRKSRC}/pyfda/pyfda_log.conf ${WRKSRC}/pyfda/pyfda_log.conf.sample
	@${MV} ${WRKSRC}/pyfda/pyfda_log_debug.conf ${WRKSRC}/pyfda/pyfda_log_debug.conf.sample

post-patch:
	@${REINPLACE_CMD} -e " \
		s|package_data={'pyfda': \['pyfda_log.conf', 'pyfda_log_debug.conf',|package_data={'pyfda': [|; \
		s|data_files = \[|data_files = [('${PREFIX}/etc', ['pyfda/pyfda_log.conf.sample', 'pyfda/pyfda_log_debug.conf.sample'])|" \
		${WRKSRC}/setup.py
	@${REINPLACE_CMD} -e " \
		s|logging.config.fileConfig(os.path.join(base_dir, rc.log_config_file))|logging.config.fileConfig(os.path.join('${PREFIX}/etc', rc.log_config_file))|" \
		${WRKSRC}/pyfda/pyfdax.py
	@${REINPLACE_CMD} -e " \
		s|'pyfda.log'|'/tmp/pyfda.log'|" \
		${WRKSRC}/pyfda/*.conf.sample

post-stage:
	@${REINPLACE_CMD} -E " \
		s|(.*\.sample)$$|@sample \1|" \
		${WRKDIR}/.PLIST.pymodtmp

.include <bsd.port.mk>
