PORTNAME=	ExtUtils-MakeMaker
PORTVERSION=	7.76
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Designed to write a Makefile for an extension module
WWW=		https://metacpan.org/release/ExtUtils-MakeMaker

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

CONFLICTS_INSTALL=	p5-ExtUtils-Command

post-patch:
	@${RM} -r ${WRKSRC}/bundled/

.include <bsd.port.mk>
