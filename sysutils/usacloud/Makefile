PORTNAME=	usacloud
DISTVERSIONPREFIX=	v
DISTVERSION=	1.14.1
CATEGORIES=	sysutils

MAINTAINER=	nork@FreeBSD.org
COMMENT=	CLI client for SAKURA cloud
WWW=		https://docs.usacloud.jp/usacloud/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		go:modules

GO_MODULE=	github.com/sacloud/usacloud
GO_TARGET=	main.go:usacloud

PLIST_FILES=	bin/usacloud \
		etc/bash_completion.d/usacloud \
		share/zsh/site-functions/_usacloud

post-build:
	${WRKDIR}/bin/usacloud completion bash > ${WRKDIR}/usacloud
	${WRKDIR}/bin/usacloud completion zsh  > ${WRKDIR}/_usacloud

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKDIR}/usacloud  ${STAGEDIR}${PREFIX}/etc/bash_completion.d/
	${INSTALL_DATA} ${WRKDIR}/_usacloud ${STAGEDIR}${PREFIX}/share/zsh/site-functions/

.include <bsd.port.mk>
