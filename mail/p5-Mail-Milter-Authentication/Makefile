PORTNAME=	Mail-Milter-Authentication
PORTVERSION=	3.20240205
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	nork@FreeBSD.org
COMMENT=	Perl Mail Authentication Milter
WWW=		https://metacpan.org/release/Mail-Milter-Authentication/

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-File-ShareDir-Install>0:devel/p5-File-ShareDir-Install
RUN_DEPENDS=	p5-App-Cmd>0:devel/p5-App-Cmd \
		p5-Clone>0:devel/p5-Clone \
		p5-Date-Manip>0:devel/p5-Date-Manip \
		p5-Email-Date-Format>0:mail/p5-Email-Date-Format \
		p5-Email-Sender>0:mail/p5-Email-Sender \
		p5-Email-Simple>0:mail/p5-Email-Simple \
		p5-File-Slurp>0:devel/p5-File-Slurp \
		p5-Import-Into>0:devel/p5-Import-Into \
		p5-JSON-XS>0:converters/p5-JSON-XS \
		p5-List-MoreUtils>0:lang/p5-List-MoreUtils \
		p5-Lock-File>0:devel/p5-Lock-File \
		p5-Log-Dispatchouli>0:devel/p5-Log-Dispatchouli \
		p5-Mail-AuthenticationResults>2.20230112:mail/p5-Mail-AuthenticationResults \
		p5-Mail-BIMI>=3.20230913:mail/p5-Mail-BIMI \
		p5-Mail-DataFeed-Abusix>=1.20200617.1:mail/p5-Mail-DataFeed-Abusix \
		p5-Mail-DKIM>=1.20200824:mail/p5-Mail-DKIM \
		p5-Mail-DMARC>=1.20160612:mail/p5-Mail-DMARC \
		p5-Mail-SPF>0:mail/p5-Mail-SPF \
		p5-Net-DNS-Resolver-Mock>=1.20171219:dns/p5-Net-DNS-Resolver-Mock \
		p5-Net-DNS>=1.01:dns/p5-Net-DNS \
		p5-Net-IP>0:net-mgmt/p5-Net-IP \
		p5-Net-Server>0:net/p5-Net-Server \
		p5-Proc-ProcessTable>0:devel/p5-Proc-ProcessTable \
		p5-Prometheus-Tiny-Shared>=0.020:net-mgmt/p5-Prometheus-Tiny-Shared \
		p5-Sereal>0:converters/p5-Sereal \
		p5-SUPER>0:devel/p5-SUPER \
		p5-Test-File-Contents>0:devel/p5-Test-File-Contents \
		p5-Text-Table>0:textproc/p5-Text-Table \
		p5-TimeDate>0:devel/p5-TimeDate \
		p5-TOML>0:textproc/p5-TOML
TEST_DEPENDS=	p5-Crypt-OpenSSL-RSA>0:security/p5-Crypt-OpenSSL-RSA \
		p5-Test-CheckManifest>0:devel/p5-Test-CheckManifest \
		p5-Test-Exception>0:devel/p5-Test-Exception \
		p5-Test-Perl-Critic>0:textproc/p5-Test-Perl-Critic

USES=		perl5
USE_PERL5=	configure
USE_RC_SUBR=	authentication_milter

TEST_ENV=	AUTHOR_TESTING=1 \
		RELEASE_TESTING=1 \
		TEST_AUTHOR=1

CACHEDIR=	/var/cache/auth_milter
ETCDIR=		${PREFIX}/etc/mail
LOGDIR=		/var/log
RUNDIR=		/var/run/auth_milter
SPOOLDIR=	/var/spool/auth_milter
VARLIBDIR=	/var/lib/auth_milter
DEFAULT_USER=	mailnull
DEFAULT_GROUP=	mailnull

NO_ARCH=	yes
SUB_FILES=	pkg-message
SUB_LIST=	CACHEDIR=${CACHEDIR} \
		LOGDIR=${LOGDIR} \
		RUNDIR=${RUNDIR} \
		SPOOLDIR=${SPOOLDIR} \
		VARLIBDIR=${VARLIBDIR}
SUB_LIST+=	DEFAULT_GROUP=${DEFAULT_GROUP} \
		DEFAULT_USER=${DEFAULT_USER}
PLIST_SUB=	${SUB_LIST}

post-extract:
		${RM} ${WRKSRC}/share/authentication_milter.init

post-patch:
		${REINPLACE_CMD} \
			-e "s|%%CACHEDIR%%|${CACHEDIR}|g" \
			-e "s|%%ETCDIR%%|${ETCDIR}|g" \
			-e "s|%%LOGDIR%%|${LOGDIR}|g" \
			-e "s|%%PREFIX%%|${PREFIX}|g" \
			-e "s|%%RUNDIR%%|${RUNDIR}|g" \
			-e "s|%%SPOOLDIR%%|${SPOOLDIR}|g" \
			-e "s|%%VARLIBDIR%%|${VARLIBDIR}|g" \
			-e "s|%%DEFAULT_USER%%|${DEFAULT_USER}|g" \
			-e "s|%%DEFAULT_GROUP%%|${DEFAULT_GROUP}|g" \
			${PATCH_WRKSRC}/bin/authentication_milter \
			${PATCH_WRKSRC}/lib/Mail/Milter/Authentication/Config.pm \
			${PATCH_WRKSRC}/lib/Mail/Milter/Authentication/Handler/DMARC.pm \
			${PATCH_WRKSRC}/share/authentication_milter.json

post-install:
		${MKDIR} ${STAGEDIR}${RUNDIR} \
			 ${STAGEDIR}${CACHEDIR} \
			 ${STAGEDIR}${SPOOLDIR} \
			 ${STAGEDIR}${VARLIBDIR} \
			 ${STAGEDIR}${ETCDIR}/authentication_milter.d

.include <bsd.port.mk>
