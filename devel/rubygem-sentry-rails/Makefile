PORTNAME=	sentry-rails
PORTVERSION=	5.23.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Client interface for the Sentry error logger
WWW=		https://github.com/getsentry/sentry-ruby

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-railties-gitlab>=5.0.0:www/rubygem-railties-gitlab \
		rubygem-sentry-ruby>=5.23.0<5.24:devel/rubygem-sentry-ruby

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
