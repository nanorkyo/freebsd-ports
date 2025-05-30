PORTNAME=	moreutils
PORTVERSION=	0.70
CATEGORIES=	sysutils
MASTER_SITES=	https://git.joeyh.name/index.cgi/moreutils.git/snapshot/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Additional Unix utilities
WWW=		https://joeyh.name/code/moreutils/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	p5-IPC-Run>=0:devel/p5-IPC-Run

USES=		gmake perl5 shebangfix

ALL_TARGET=	errnos.h ${CANNED_MANPAGES:R}
MAKE_JOBS_UNSAFE=	yes

CANNED_MANPAGES=errno.1 \
		ifdata.1 \
		ifne.1 \
		isutf8.1 \
		lckdo.1 \
		mispipe.1 \
		moreutils-parallel.1 \
		pee.1 \
		sponge.1
PERL_MANPAGES=	chronic.1 \
		combine.1 \
		moreutils-ts.1 \
		vidir.1 \
		vipe.1 \
		zrun.1

SHEBANG_FILES=	${PERL_MANPAGES:R}

OPTIONS_DEFINE=	MANPAGES
OPTIONS_DEFAULT=MANPAGES
OPTIONS_SUB=	yes

post-extract:
.for file in parallel.c parallel.docbook ts
	@${MV} ${WRKSRC}/${file} ${WRKSRC}/moreutils-${file}
.endfor

post-patch:
	@cd ${FILESDIR}/ && ${CP} ${CANNED_MANPAGES} ${WRKSRC}/

post-build:
.for man in ${PERL_MANPAGES:R}
	${LOCALBASE}/bin/pod2man --center=moreutils --release=${PORTVERSION} ${WRKSRC}/${man} > ${WRKSRC}/${man}.1
.endfor

do-install:
	cd ${WRKSRC}/ && ${INSTALL_PROGRAM} ${CANNED_MANPAGES:R} ${STAGEDIR}${PREFIX}/bin/
	cd ${WRKSRC}/ && ${INSTALL_SCRIPT} ${PERL_MANPAGES:R} ${STAGEDIR}${PREFIX}/bin/
	cd ${WRKSRC}/ && ${INSTALL_MAN} ${CANNED_MANPAGES} ${PERL_MANPAGES} ${STAGEDIR}${PREFIX}/share/man/man1/

# maintainer section:
# require: docbook-xsl, libxml2, libxslt

updateman: do-clean extract
.for man in ${CANNED_MANPAGES:R}
	${LOCALBASE}/bin/xmllint --noout --valid ${WRKSRC}/${man}.docbook && \
	${LOCALBASE}/bin/xsltproc --output ${FILESDIR}/${man}.1 --param man.authors.section.enabled 0 ${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl ${WRKSRC}/${man}.docbook
.endfor
	${MV} ${FILESDIR}/parallel.1 ${FILESDIR}/moreutils-parallel.1

.include <bsd.port.mk>
