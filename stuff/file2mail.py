import smtplib
import os
import sys
from email.mime.multipart import MIMEMultipart
from email.mime.application import MIMEApplication
from email.mime.text import MIMEText
from email.utils import make_msgid
from email.utils import formatdate


def make_mail(me, you, filename):
    msg = MIMEMultipart()
    msg['To'] = me
    msg['From'] = you
    msg['Message-Id'] = make_msgid()
    msg['Date'] = formatdate(localtime=True)
    msg.attach(MIMEText('here it is', 'plain'))
    part = MIMEApplication(open(filename).read())
    part.add_header('Content-Disposition', 'attachment; filename="%s"' % os.path.basename(filename))
    msg.attach(part)
    return msg

def send_mail(msg, email, password):
    srv = smtplib.SMTP('smtp.gmail.com')
    srv.set_debuglevel(1)
    srv.ehlo()
    srv.starttls()
    srv.ehlo()
    srv.login(email, password)
    srv.sendmail(msg['From'], msg['To'], msg.as_string())
    srv.quit()

if __name__=="__main__":
    me = sys.argv[1]
    you = sys.argv[3]
    what = sys.argv[4]
    msg = make_mail(me, you, what)
    send_mail(msg, me, sys.argv[2])
