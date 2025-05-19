PORTNAME=	usacloud
PORTVERSION=	1.15.0
DISTVERSIONPREFIX=	v
PORTREVISION=	0
CATEGORIES=	sysutils
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	nork@FreeBSD.org
COMMENT=	CLI client for SAKURA cloud
WWW=		https://docs.usacloud.jp/usacloud/

LICENSE=	APACHE20

FLAVORS=	default core
FLAVOR?=	${FLAVORS:[1]}
FLAVORS_SUB=	yes

core_PKGNAMESUFFIX=	-core
default_BUILD_DEPENDS=	${PORTNAME}${core_PKGNAMESUFFIX}>=${PKGVERSION}:sysutils/usacloud@core
default_RUN_DEPENDS=	${PORTNAME}${core_PKGNAMESUFFIX}>=${PKGVERSION}:sysutils/usacloud@core

.if ${FLAVOR:U} == core
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		go:modules

GO_MODULE=	github.com/sacloud/usacloud
GO_TARGET=	main.go:usacloud

PLIST_FILES=	bin/usacloud
.else
NO_ARCH=	yes
NO_TEST=	yes
NO_WRKSUBDIR=	yes

USACLOUD_CMD=	${LOCALBASE}/bin/usacloud completion
ENTRIES=	bash:etc/bash_completion.d/usacloud \
		zsh:share/zsh/site-functions/_usacloud
M_LABEL=	C,\:.*$$,,
M_PATH=		C,^.*\:,,
PLIST_FILES=	${ENTRIES:${M_PATH}}

do-build:
	cd ${BUILD_WRKSRC} && \
	   ${MKDIR} ${ENTRIES:${M_PATH}:H} && \
	   ${ENTRIES:@F@${USACLOUD_CMD} ${F:${M_LABEL}} > ${F:${M_PATH}};@}

do-install:
	cd ${INSTALL_WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}
.endif

.include <bsd.port.mk>
