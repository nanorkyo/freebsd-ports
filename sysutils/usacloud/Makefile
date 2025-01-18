PORTNAME=	${DISTNAME}
CATEGORIES=	sysutils
MASTER_SITES=	# not applicable
DISTFILES=	# not applicable

MAINTAINER=	nork@FreeBSD.org
COMMENT=	Meta port for SAKURA cloud
WWW=		https://docs.usacloud.jp/usacloud/

LICENSE=	APACHE20

BUILD_DEPENDS=	usacloud:sysutils/usacloud-core
RUN_DEPENDS=	usacloud:sysutils/usacloud-core

NO_ARCH=	yes
NO_TEST=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	etc/bash_completion.d/usacloud \
		share/zsh/site-functions/_usacloud

do-build:
	usacloud completion bash > ${WRKDIR}/usacloud
	usacloud completion zsh  > ${WRKDIR}/_usacloud

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKDIR}/usacloud  ${STAGEDIR}${PREFIX}/etc/bash_completion.d/
	${INSTALL_DATA} ${WRKDIR}/_usacloud ${STAGEDIR}${PREFIX}/share/zsh/site-functions/

.include "${.CURDIR}/../usacloud-core/Makefile.version"
.include <bsd.port.mk>
