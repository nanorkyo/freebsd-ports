PORTNAME=	derailed_benchmarks
PORTVERSION=	2.2.1
CATEGORIES=	benchmarks rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Benchmarks for your whole Rails app
WWW=		https://github.com/schneems/derailed_benchmarks

LICENSE=	MIT

RUN_DEPENDS=	rubygem-base64>=0:converters/rubygem-base64 \
		rubygem-benchmark-ips>=2.0.0<3:benchmarks/rubygem-benchmark-ips \
		rubygem-bigdecimal>=0:math/rubygem-bigdecimal \
		rubygem-drb>=0:devel/rubygem-drb \
		rubygem-get_process_mem>=0:devel/rubygem-get_process_mem \
		rubygem-heapy>=0<1:devel/rubygem-heapy \
		rubygem-memory_profiler>=0<2:devel/rubygem-memory_profiler \
		rubygem-mini_histogram>=0.3.0:devel/rubygem-mini_histogram\
		rubygem-mutex_m>=0:devel/rubygem-mutex_m \
		rubygem-ostruct>=0:devel/rubygem-ostruct \
		rubygem-rack>=1:www/rubygem-rack \
		rubygem-rack-test>=0:www/rubygem-rack-test \
		rubygem-rake>=10<14:devel/rubygem-rake \
		rubygem-ruby2_keywords>=0:devel/rubygem-ruby2_keywords \
		rubygem-ruby-statistics>=4.0.1:devel/rubygem-ruby-statistics \
		rubygem-thor>=0.19<2:devel/rubygem-thor

USES=		gem

CONFLICTS_INSTALL=	rubygem-gitlab-derailed_benchmarks

NO_ARCH=	yes

PLIST_FILES=	bin/derailed

.include <bsd.port.mk>
