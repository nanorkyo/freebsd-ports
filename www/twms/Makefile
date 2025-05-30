PORTNAME=	twms
PORTVERSION=	0.06y
PORTREVISION=	2
CATEGORIES=	www astro

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tiny WMS server
WWW=		https://github.com/Komzpa/twms

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyproj>0:graphics/py-pyproj@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}webpy>0:www/webpy@${PY_FLAVOR} \
		${PY_PILLOW} \
		${PYTHON_PKGNAMEPREFIX}cairo>0:graphics/py-cairo@${PY_FLAVOR} \
		${FREESANS}:x11-fonts/freefont-ttf

USE_GITHUB=	yes
GH_ACCOUNT=	Komzpa

USES=		python
USE_PYTHON=	distutils py3kplist optsuffix
NO_ARCH=	yes

FREESANS=	${LOCALBASE}/share/fonts/freefont-ttf/FreeSans.ttf

USE_RC_SUBR=	twms

USERS=		twms
GROUPS=		twms

PLIST_SUB=	USER=${USERS} GROUP=${GROUPS}
SUB_LIST=	USER=${USERS} PYTHON_CMD="${PYTHON_CMD}"

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/twms/twms.conf|${PREFIX}/etc/twms/twms.conf|' \
		${WRKSRC}/twms/twms.py
	@${REINPLACE_CMD} -e '/install_path/ s|/usr/share/twms/|${DATADIR}/|' \
		-e 's|/usr/share/fonts/truetype/freefont/FreeSans.ttf|${FREESANS}|' \
		${WRKSRC}/twms/twms.conf

post-install:
	@${MV} ${STAGEDIR}${ETCDIR}/twms.conf ${STAGEDIR}${ETCDIR}/twms.conf.sample
	@${RM} ${STAGEDIR}${DOCSDIR}/COPYING
	@${RM} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/twms/twms.conf
	@${MKDIR} ${STAGEDIR}/var/cache/twms/tiles
	@${MKDIR} ${STAGEDIR}/var/cache/twms/traces

.include <bsd.port.mk>
