PORTNAME=	kerl
DISTVERSION=	4.4.0
CATEGORIES=	devel
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Virtualenv-like tool for Erlang/OTP
WWW=		https://github.com/kerl/kerl

RUN_DEPENDS=	${LOCALBASE}/bin/curl:ftp/curl

USE_GITHUB=	yes

NO_BUILD=	yes

PLIST_FILES=	bin/kerl
PORTDOCS=	README.md

OPTIONS_DEFINE=		BASH DOCS ZSH
OPTIONS_DEFAULT=	BASH ZSH

BASH_PLIST_FILES=	share/bash-completion/completions/kerl
ZSH_PLIST_FILES=	share/zsh/site-functions/_kerl

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/kerl ${STAGEDIR}${PREFIX}/bin

do-install-BASH-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/bash-completion/completions
	${INSTALL_DATA} ${WRKSRC}/bash_completion/kerl \
		${STAGEDIR}${PREFIX}/share/bash-completion/completions/

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

do-install-ZSH-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions/
	${INSTALL_DATA} ${WRKSRC}/zsh_completion/_kerl \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions/

.include <bsd.port.mk>
