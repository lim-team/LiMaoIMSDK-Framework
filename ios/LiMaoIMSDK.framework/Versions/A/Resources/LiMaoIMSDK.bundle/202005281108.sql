alter table `message` add column client_msg_no varchar(40) not null default ''; -- 客户端唯一编号

CREATE  INDEX IF NOT EXISTS idx_client_msg_no ON message (client_msg_no);
