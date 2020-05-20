
alter table `conversation` add column last_msg_seq INTEGER not null default 0; -- 最后一条消息message_seq

alter table `message` add column searchable_word text not null default ''; -- 消息可以索引的关键字

