PORTNAME=	CGI-Application-Plugin-TT
DISTVERSION=	1.06
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Add Template Toolkit support to CGI::Application
WWW=		https://metacpan.org/release/CGI-Application-Plugin-TT

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-CGI-Application>=0:www/p5-CGI-Application \
		p5-Template-Toolkit>=0:www/p5-Template-Toolkit \
		p5-Class-ISA>=0:devel/p5-Class-ISA

USES=		perl5
USE_PERL5=	configure

OPTIONS_DEFINE=	DEVPOPUP
OPTIONS_DEFAULT=DEVPOPUP
DEVPOPUP_DESC=	Include support for run-time reports
DEVPOPUP_BUILD_DEPENDS=	p5-CGI-Application-Plugin-DevPopup>=0:www/p5-CGI-Application-Plugin-DevPopup
DEVPOPUP_RUN_DEPENDS:=	${DEVPOPUP_BUILD_DEPENDS}

.include <bsd.port.mk>
