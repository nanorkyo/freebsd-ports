PORTNAME=	namazu
PORTVERSION=	${NAMAZU_PORTVERSION}
PORTREVISION=	1
CATEGORIES=	japanese databases www textproc
PKGNAMESUFFIX=	2

MAINTAINER=	mew14930xvi@inbox.lv
COMMENT=	Meta-port of Namazu and Japanese support modules
WWW=		http://www.namazu.org/

LIB_DEPENDS=	libnmz.so:databases/namazu2
RUN_DEPENDS=	ja-p5-nkf>=0:japanese/p5-nkf

.if defined(WITH_CHASEN)
RUN_DEPENDS+=	ja-p5-Text-ChaSen>=0:japanese/p5-Text-ChaSen
.elif defined(WITH_KAKASI)
RUN_DEPENDS+=	ja-p5-Text-Kakasi>=0:japanese/p5-Text-Kakasi
.else
RUN_DEPENDS+=	ja-p5-MeCab>=0:japanese/p5-MeCab
.endif

.include "${.CURDIR}/../../databases/namazu2/Makefile.common"

USES=		metaport perl5

.include <bsd.port.mk>
